n = int(input())
rooms = 0

for i in range(n):
    q, i = map(int, input().split())
    rooms += i - q > 2
    
print (rooms)