#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <inttypes.h>

#define APP_NAME "Factorial Engine Pro"
#define APP_VERSION "1.0.0"

#define MAX_INPUT 128
#define MAX_N 1000
#define MAX_DIGITS 3000

typedef enum {
    STATUS_OK = 0,
    STATUS_INVALID_INPUT,
    STATUS_OUT_OF_RANGE,
    STATUS_CAPACITY_EXCEEDED
} Status;

typedef struct {
    int digits[MAX_DIGITS];
    size_t length;
} BigInteger;

static Status read_integer(const char *prompt, int64_t *value)
{
    char buffer[MAX_INPUT];
    char *end;
    intmax_t parsed;

    printf("%s", prompt);

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return STATUS_INVALID_INPUT;
    }

    if (strchr(buffer, '\n') == NULL && !feof(stdin)) {
        int ch;

        while ((ch = getchar()) != '\n' && ch != EOF) {
        }

        return STATUS_INVALID_INPUT;
    }

    errno = 0;
    end = NULL;

    parsed = strtoimax(buffer, &end, 10);

    if (buffer == end || errno == ERANGE) {
        return STATUS_INVALID_INPUT;
    }

    while (isspace((unsigned char)*end)) {
        end++;
    }

    if (*end != '\0') {
        return STATUS_INVALID_INPUT;
    }

    *value = (int64_t)parsed;

    return STATUS_OK;
}

static void bigint_init(BigInteger *number, int initial_value)
{
    number->digits[0] = initial_value;
    number->length = 1;
}

static Status bigint_multiply(BigInteger *number, unsigned int multiplier)
{
    uint64_t carry = 0;
    size_t i;

    for (i = 0; i < number->length; i++) {
        uint64_t product =
            (uint64_t)number->digits[i] * multiplier + carry;

        number->digits[i] = (int)(product % 10);
        carry = product / 10;
    }

    while (carry > 0) {
        if (number->length >= MAX_DIGITS) {
            return STATUS_CAPACITY_EXCEEDED;
        }

        number->digits[number->length] = (int)(carry % 10);
        number->length++;

        carry /= 10;
    }

    return STATUS_OK;
}

static Status calculate_factorial(unsigned int n, BigInteger *result)
{
    unsigned int multiplier;
    Status status;

    bigint_init(result, 1);

    for (multiplier = 2; multiplier <= n; multiplier++) {
        status = bigint_multiply(result, multiplier);

        if (status != STATUS_OK) {
            return status;
        }
    }

    return STATUS_OK;
}

static void bigint_print(const BigInteger *number)
{
    size_t i = number->length;

    while (i > 0) {
        i--;
        printf("%d", number->digits[i]);
    }

    printf("\n");
}

static void calculate_single(void)
{
    int64_t input;
    BigInteger result;
    Status status;

    if (read_integer(
            "Enter a non-negative integer (0-1000): ",
            &input) != STATUS_OK) {

        printf("[ERROR] Invalid integer input.\n");
        return;
    }

    if (input < 0 || input > MAX_N) {
        printf("[ERROR] The number must be between 0 and %d.\n", MAX_N);
        return;
    }

    status = calculate_factorial((unsigned int)input, &result);

    if (status != STATUS_OK) {
        printf("[ERROR] The result exceeded the supported capacity.\n");
        return;
    }

    printf("\n");
    printf("========================================\n");
    printf("             FACTORIAL REPORT\n");
    printf("========================================\n");
    printf("%" PRId64 "! = ", input);

    bigint_print(&result);

    printf("Number of decimal digits: %zu\n", result.length);
    printf("========================================\n\n");
}

static void calculate_series(void)
{
    int64_t limit;
    int64_t i;
    BigInteger result;
    Status status;

    if (read_integer(
            "Calculate factorials from 0 to N. Enter N (0-100): ",
            &limit) != STATUS_OK) {

        printf("[ERROR] Invalid input.\n");
        return;
    }

    if (limit < 0 || limit > 100) {
        printf("[ERROR] N must be between 0 and 100.\n");
        return;
    }

    printf("\n");
    printf("========================================\n");
    printf("            FACTORIAL SERIES\n");
    printf("========================================\n");

    for (i = 0; i <= limit; i++) {
        status = calculate_factorial((unsigned int)i, &result);

        if (status != STATUS_OK) {
            printf("[ERROR] Calculation failed for %" PRId64 ".\n", i);
            return;
        }

        printf("%" PRId64 "! = ", i);
        bigint_print(&result);
    }

    printf("========================================\n\n");
}

static void show_menu(void)
{
    printf("========================================\n");
    printf("       %s\n", APP_NAME);
    printf("                Version %s\n", APP_VERSION);
    printf("========================================\n");
    printf("1. Calculate a factorial\n");
    printf("2. Generate a factorial series\n");
    printf("0. Exit\n");
    printf("========================================\n");
}

int main(void)
{
    int64_t option;

    while (true) {
        show_menu();

        if (read_integer("Select an option: ", &option) != STATUS_OK) {
            printf("\n[ERROR] Invalid menu input.\n\n");
            continue;
        }

        switch (option) {
            case 1:
                calculate_single();
                break;

            case 2:
                calculate_series();
                break;

            case 0:
                printf("\nClosing %s...\n", APP_NAME);
                printf("Thank you for using the application.\n");
                return EXIT_SUCCESS;

            default:
                printf("\n[ERROR] Option not recognized.\n\n");
                break;
        }
    }
}