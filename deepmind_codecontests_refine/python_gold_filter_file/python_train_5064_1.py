n = int(input())

def insert(s,t,ret,string,c,scount,tcount):
  maxval = s*tcount
  val = maxval
  maxpos = 0
  for i in range(len(string)):
    si, ti, ci = string[i]
    val = val + si*t*ci - s*ti*ci
    if maxval < val:
      maxval = val
      maxpos = i+1
  string = string[:maxpos] + [(s,t,c)] + string[maxpos:]

  return ret+maxval*c, string

def count2(m, memo):
  if m in memo:
    return memo[m]
  s = 0
  ret = 0
  for c in m:
    if c == 's':
      s += 1
    else:
      ret += s
  memo[m] = (ret,s)
  return ret, s



memo = {}
ret = 0
d = {}
for _ in range(n):
  m = input()
  c,s = count2(m, memo)
  ret += c
  t = len(m)-s
  if (s,t) not in d:
    d[(s,t)] = 0
  ret += s*t*d[(s,t)]
  d[(s,t)] += 1

string = []
scount = 0
tcount = 0
for s,t in d:
  c = d[(s,t)]
  ret, string = insert(s,t,ret,string,c,scount,tcount)
  scount += s*c
  tcount += t*c


print(ret)