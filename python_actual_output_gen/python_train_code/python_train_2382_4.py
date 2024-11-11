

left_accordion_stack = ["[", ":"]
right_accordion_stack = ["]", ":"]


def accordion(s):
  accordion_len = 4
  l_pointer = 0
  while (l_pointer < len(s) and left_accordion_stack):
    if s[l_pointer] == left_accordion_stack[0]:
      left_accordion_stack.pop(0)
    
    l_pointer += 1

  r_pointer = len(s)-1
  while (r_pointer > l_pointer and right_accordion_stack):
    if s[r_pointer] == right_accordion_stack[0]:
      right_accordion_stack.pop(0)
    r_pointer -= 1

  if (not (right_accordion_stack) and not (left_accordion_stack)):
    for i in range(l_pointer, r_pointer+1):
      if (s[i] == "|"):
        accordion_len += 1
    return accordion_len
  else:
    return -1

s = input()
print(accordion(s))