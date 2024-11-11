input()
a = input().replace('(', ')').split(')')
print(max(len(w) for s in a[::2] for w in s.split('_')), len([w for s in a[1::2] for w in s.split('_') if(w)]))