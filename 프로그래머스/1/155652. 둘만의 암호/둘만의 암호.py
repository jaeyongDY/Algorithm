def solution(s, skip, index):
    answer = ''
    for word in s :
        i = 0
        ordWord = ord(word)
        while i < index :
            ordWord = ordWord + 1
            
            if ordWord > ord('z') :
                ordWord = ord('a')

            if chr(ordWord) not in skip :
                i+=1
        answer += chr(ordWord)
    return answer