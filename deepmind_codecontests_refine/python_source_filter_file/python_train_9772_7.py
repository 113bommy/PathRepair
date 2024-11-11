c = list(input())
print(['YES','NO'][('N' in c)^('S' in c)or('E' in c)^('W' in c)])