A,B,C,D = map(int, input().split())
if -(-C // B) <= -(-A // D):
    print('yes')
else:
    print('no')