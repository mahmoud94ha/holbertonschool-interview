#!/usr/bin/python3
"""0. Prime Game"""


def prime_number_check(num):
    """Prototype: def is_prime_number(n)"""
    for i in range(2, int(num ** 0.5) + 1):
        if not num % i:
            return False
    return True


def round_checker(round_number, prime_list):
    """Prototype: def determine_round_winner"""
    prime_count = sum((i != 0 and i <= round_number)
                      for i in prime_list[:round_number + 1])
    return "Maria" if prime_count % 2 else "Ben"

def prime_number_adder(num, prime_list):
    """Prototype: def add_prime_number(n, primes_list)"""
    l_prime = prime_list[-1]
    if num > l_prime:
        for i in range(l_prime + 1, num + 1):
            if prime_number_check(i):
                prime_list.append(i)
            else:
                prime_list.append(0)


def isWinner(num_rounds, round_values):
    """Prototype: def isWinner(x, nums)"""
    players_score = {"Maria": 0, "Ben": 0}
    primes = [0, 0, 2]
    prime_number_adder(max(round_values), primes)

    for current_round in range(num_rounds):
        round_winner = round_checker(round_values[current_round],
                                              primes)
        if round_winner:
            players_score[round_winner] += 1

    if players_score["Maria"] > players_score["Ben"]:
        return "Maria"
    elif players_score["Ben"] > players_score["Maria"]:
        return "Ben"

    return None
