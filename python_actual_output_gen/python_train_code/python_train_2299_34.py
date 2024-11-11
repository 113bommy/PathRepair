n = int(input())
l = map(int, input().split())
b = all([i%3==0 and i%5==0 for i in l if i%2 == 0])
print('APPROVED' if b else 'DENIED')