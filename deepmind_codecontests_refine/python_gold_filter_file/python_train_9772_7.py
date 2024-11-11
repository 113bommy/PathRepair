c = list(input())
print(['Yes','No'][('N' in c)^('S' in c)or('E' in c)^('W' in c)])