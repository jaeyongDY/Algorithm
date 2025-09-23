from collections import deque
import sys

n = int(input())
q_student = deque()
max_len = 0
last_student = 0

for _ in range(n):
    data = sys.stdin.readline().split()
    if data[0] == '1':  # 입장
        student = int(data[1])
        q_student.append(student)
        if len(q_student) > max_len:
            max_len = len(q_student)
            last_student = student
        elif len(q_student) == max_len:
            last_student = min(last_student, student)
    else:  # 퇴장
        if q_student:
            q_student.popleft()

print(max_len, last_student)