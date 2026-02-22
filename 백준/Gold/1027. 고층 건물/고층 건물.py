n = int(input())
b = list(map(int, input().split()))

max_count = 1

if n == 1 :
    print(0)
else :


    for i in range(n) :
        count = 0
        # i 건물기준으로 순횐
        for j in range(n) :
            # i기준으로 j건물들을 돌때 같은 건물은 pass
            if i == j :
                continue
            
            visible = True

            # i와 j의 건물 사이 값을 구하기위함...
            for k in range(min(i, j) + 1, max(i, j)) :
                h = b[i] + (b[i] - b[j]) * (k-i) / (i - j)

                if b[k] >= h :
                    visible = False
                    break

            if visible :
                count += 1
        
        max_count = max(max_count, count)

    print(max_count)