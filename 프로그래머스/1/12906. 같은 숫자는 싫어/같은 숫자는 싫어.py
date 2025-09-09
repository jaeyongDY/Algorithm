def solution(arr):
    answer = []
    pre = -1
    for index in range(0, len(arr)) :
        if pre == arr[index] :
            continue
        else :
            pre = arr[index]
            answer.append(arr[index])
    return answer