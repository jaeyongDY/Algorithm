while True :

    n = int(input())

    if n == 0 :
        break


    data = input()

    rows = int(len(data) / n)

    result = []
    resultData = ""
    index = 0
    # even -> left to right
    # odd -> right to left
    for i in range(0, rows) :
        result.append([])
        index =  ((i + 1)  if i % 2 == 1 else i) * n
        if i % 2 == 1 : 
            index = (i + 1) * n - 1
        else :
            index = i * n
        for j in range(0, n) :
            result[i].append(data[index])
            index = index - 1 if i % 2 == 1 else index + 1
    
    for i in range(0, n) :
        for j in range(0, rows) :
            resultData += result[j][i]

    print(resultData)
