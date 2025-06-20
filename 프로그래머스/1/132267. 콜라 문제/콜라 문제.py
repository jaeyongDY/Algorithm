def solution(a, b, n):
    answer = 0
    # 1. 빈 병의 개수 n이 교환 가능한 최소 숫자 a 이상일 때까지 반복
    while n >= a:
        # 2. b개의 병 추가
        answer += b
        # 3. 남은 병 계산하기
        n = n - a + b
    return answer
