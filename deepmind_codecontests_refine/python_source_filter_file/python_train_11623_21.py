V1, V2, V3, Vm = map(int, input().split())
if Vm >= V2 or 2 * min(V3, Vm) <= max(V3, Vm):
    print(-1)
else:
    print(2 * V1, 2 * V2, 2 * min(V3, Vm), sep = '\n')