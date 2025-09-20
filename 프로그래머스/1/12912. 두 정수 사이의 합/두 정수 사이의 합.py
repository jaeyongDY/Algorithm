def solution(a, b):
    answer = 0
    if b < a :
        t = a
        a = b
        b = t
    for i in range(a, b+1) :
        answer += i
    return answer