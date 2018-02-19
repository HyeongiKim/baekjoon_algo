commands = []
stack = []
n = input()
for i in range(n):
    commands.append(raw_input())

for e in commands:
    cm = e.split()
    if cm[0] == 'push':
        stack.append(int(cm[1]))
    elif cm[0] == 'pop':
        if stack == []:
            print -1
        else:
            print stack.pop(-1)
    elif cm[0] == 'size':
        print len(stack)
    elif cm[0] == 'empty':
        print (1 if len(stack) == 0 else 0)
    elif cm[0] == 'top':
        if stack == []:
            print -1
        else:
            print stack[-1]
