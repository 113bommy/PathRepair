input()
li = map(int,input().split())

print('NO' if len(li) > len(set(li)) else 'YES')