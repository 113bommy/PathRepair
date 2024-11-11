n = int(input())
for i in range(n):
    q = input()
    if(q.endswith('po')):
        print('FILIPINO')
    if(q.endswith('mnida')):
        print('KOREAN')
    if(q.endswith('desu') or q.endswith('mesu')):
        print('JAPANESE')