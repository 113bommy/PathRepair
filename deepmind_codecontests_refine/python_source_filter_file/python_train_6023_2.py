h,w = map(int, input().split())
s = [h//2+w//3+1, h//3+w//2+1]
if h%3 == 0 or w%3 == 0:
  s += [0]
if h%2 == 0:
  s += [h//2]
if w%2 == 0:
  s += [w//2]
print(min(s))