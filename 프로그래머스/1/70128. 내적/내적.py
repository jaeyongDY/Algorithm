def solution(a, b):
    answer = 0
    _len = len(a)
    for i in range(_len) :
        answer = answer + (a[i] * b[i])
    
    return answer