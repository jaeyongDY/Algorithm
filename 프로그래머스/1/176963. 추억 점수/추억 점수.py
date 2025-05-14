def solution(name, yearning, photo):
    answer = []
    
    for data in photo :
        result = 0
        for eachData in data :
            if eachData in name :
                result += yearning[name.index(eachData)]
        
        answer.append(result)
    return answer
