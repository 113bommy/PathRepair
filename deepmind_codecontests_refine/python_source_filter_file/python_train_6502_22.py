import math
parter,group = [int(x) for x in input().split()]
ans = 0
m2 = parter - (group-1)
m_min = int(parter/group)
gr_max = parter%group
m_max = m_min+1
gr_min = group-gr_max

ans = int(m_min*(m_min-1)*gr_min/2+m_max*(m_max-1)*gr_max/2)

print(str(ans)+' '+str(int(m2*(m2-1)/2)))