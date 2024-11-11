A,B,C = map(int,input().split())

C = min(C, A+B+1)
answer = A+C
print(answer)