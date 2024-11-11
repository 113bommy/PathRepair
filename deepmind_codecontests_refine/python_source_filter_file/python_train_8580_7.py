n, k = list(map(int,input().split(" ")))
ts = list(map(int,input().split(" ")))

aps = dict()
for i in range(n):
  f = ts[i] - k*i
  if f > 0:
    aps[f] = aps.get(f,0) + 1

af = max([i for i in aps.keys()], key=lambda x:aps[x])

print(len([1 for i in range(n) if ts[i] != af + k*i]))

def action(af, i, ts, k):
  if ts[i] > af+k*i:
    return "+ %i %i" % (i+1, ts[i] - (af+k*i))
  elif ts[i] < af+k*i:
    return "- " + str(i+1) + " " + str(af+(k*i) - ts[i])
  else:
    return None
    
acts = [action(af, i, ts, k) for i in range(n)]
acts = [act for act in acts if act]

print("\n".join(acts))
