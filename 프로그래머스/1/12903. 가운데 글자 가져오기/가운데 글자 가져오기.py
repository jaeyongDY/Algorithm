def solution(s):
    answer = ''
    _len = len(s)
    index = _len / 2
    if _len % 2 == 1 :
        answer = s[int(index)]
    else :
        answer = s[int(index) - 1] + s[int(index)]
    return answer