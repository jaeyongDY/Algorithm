arr = [1, 2, 3, 4]

from functools import reduce

def solution(arr):
    return reduce(lambda x, y : x + y, arr) / len(arr)

print(solution(arr)); # 2.5