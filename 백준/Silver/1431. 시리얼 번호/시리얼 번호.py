import re

n = int(input())

data = [input() for _ in range(n)]

data.sort(key=lambda x : (len(x), sum(int(num) for num in re.findall(r'\d', x)), str(x)))

for item in data :
    print(item)
