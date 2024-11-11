s = [ch for ch in input()]
Set = set(s)
List = list(Set)


if len(Set)==4 or len(Set)==3 and len(s)>3 or len(Set)==2 and s.count(List[0]) and s.count(List[-1]): print('Yes')
else: print('No')
