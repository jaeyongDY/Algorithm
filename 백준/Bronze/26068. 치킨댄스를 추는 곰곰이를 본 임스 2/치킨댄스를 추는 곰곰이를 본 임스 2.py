n = int(input())

result = 0
for i in range(n) :
    gift = input()
    if int(gift.split("-")[1]) <= 90 :
        result += 1

print(result)