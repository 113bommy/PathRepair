x,a,b = map(int,input().split())

print('delicious') if b <= a else print('safe') if b < a+b else print('dangerous')