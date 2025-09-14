n = float(input())
time = 0
i = 1
while True :
    time+=1
    if n < i :
        i = 1
    n -= i
    if n <= 0 :
        break
    else :
        i += 1
print(time)