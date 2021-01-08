#!/usr/bin/python3

"""
Minimum operations
"""


def minOperations(n):
    """
    Calculates the fewest number of operations needed to result in
    exactly n H characters in the file
    """
    if n < 2:
        return 0
    factors = []
    i = 2
    while i <= n:
        if n % i == 0:
            factors.append(i)
            n = n / i
        else:
            i += 1
    return sum(factors)
