n = int(input())
#n, m = map(int, input().split())
s = input()   
#c = list(map(int, input().split()))
l = s.find('A')
if n == 2 * l:
    print('Friendship')
elif n - l > l:
    print('Danik')
else:
    print('Anton')