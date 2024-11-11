s=input()
r = 'NA', 'MMYY', 'YYMM', 'AMBIGUOUS'
f = lambda x: 1 <= int(x) <= 12 
print(r[f(s[:2]) + 2 * f(s[2:])])
