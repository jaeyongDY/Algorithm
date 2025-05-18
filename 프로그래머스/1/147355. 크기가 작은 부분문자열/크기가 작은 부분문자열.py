def solution(t, p):
    answer = 0
    _len = len(p)

    i = 0
    while True :
        if len(t) - i <  _len:
            break
        if int(t[i: _len+i]) <= int(p) :
            answer += 1
        i+=1
        
    return answer