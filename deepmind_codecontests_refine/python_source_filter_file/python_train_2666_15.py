input()
max([(sum([(i>='A' and i<='Z') for i in x])) for x in (input().split(' '))])