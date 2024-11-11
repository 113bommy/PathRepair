import sys
v1, v2, v3, vm = map(int, input().split())
if vm <= v3 * 2 and v3 < vm * 2 and vm < v2:
    vm3 = max(vm, v3)
    vm2 = max(2 * vm + 1, v2)
    vm1 = max(vm2 + 1, v1)
    print(vm1, vm2, vm3, sep = '\n')
else:
    print(-1)


