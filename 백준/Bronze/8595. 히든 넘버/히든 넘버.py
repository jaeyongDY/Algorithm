import re

n = input()
t = input()
result = 0
for num in re.findall(r"\d+", t) :
    result += int(num)
print(result)