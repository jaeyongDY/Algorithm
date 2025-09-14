from math import sqrt
from sys import stdin
input = stdin.readline

for _ in range(int(input())):
    n = int(input())
    res = ""

    if n % 2 == 1:
        res += "O"
    if int(sqrt(n)) ** 2 == n:
        res += "S"
    if res == "":
        res = "EMPTY"

    print(res)