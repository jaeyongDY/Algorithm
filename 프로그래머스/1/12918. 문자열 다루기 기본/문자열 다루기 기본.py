def solution(s):
    answer = True
    
    if len(s) != 4 and len(s) != 6 :
        answer = False

    try:
        s = int(s)
    except ValueError:
        answer = False
    
    return answer