def solution(s):
    answer = True
    
    s = s.lower()
    p = 0
    y = 0
    
    for ch in s :
        if ch == 'y' :
            y += 1
        elif ch == 'p' :
            p +=1
    
    if p == y :
        answer = True
    else :
        answer = False
    return answer