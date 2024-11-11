n = int(input().rstrip())
s = [str(input().rstrip()) for i in range(n)]
for v in ["AC","WA","TLE","RE"]:
         print(f"{v} x {s.count(v)}")