import collections
'''
a = 2
b = 3
print(a+b)
'''

code = {
    'co_code': [
        ('LOAD_CONST', 0),
        ('STORE_NAME', 0),
        ('LOAD_CONST', 1),
        ('STORE_NAME', 1),
        ('LOAD_NAME', 0),
        ('LOAD_NAME', 1),
        ('BINARY_ADD', None),
        ('PRINT_EXPR', None)
    ],
    'co_consts': [2, 3],
    'co_names': ['a', 'b'],
}

class Interpreter:
    '''Reference: https://docs.python.org/3/library/dis.html'''

    def __init__(self):
        self.stack = collections.deque()
        self.environment = {}

    def LOAD_CONST(self, const):
        self.stack.append(const)
        '''Pushes const onto the stack.'''

    def STORE_NAME(self, name):
        self.environment[name] = self.stack.pop()
        '''Implements name = TOS.'''

    def LOAD_NAME(self, name):
        self.stack.append(self.environment[name])
        '''Pushes the value associated with name onto the stack.'''

    def BINARY_ADD(self):
        TOS = self.stack.pop()
        TOS1 = self.stack.pop()
        self.stack.append(TOS + TOS1)
        '''Implements the binary add.'''

    def PRINT_EXPR(self):
        print(self.stack.pop())
        '''TOS is removed from the stack and printed.'''

    def ceval(self, code):
        for opname, arg in code['co_code']:
            if opname == 'LOAD_CONST':
                self.LOAD_CONST(code['co_consts'][arg])
            elif opname == 'STORE_NAME':
                self.STORE_NAME(code['co_names'][arg])
            elif opname == 'LOAD_NAME':
                self.LOAD_NAME(code['co_names'][arg])
            elif opname == 'BINARY_ADD':
                self.BINARY_ADD()
            elif opname == 'PRINT_EXPR':
                self.PRINT_EXPR()
        '''Interpreter main loop.'''
        # Start instructions
        # End instructions
interpreter = Interpreter()
interpreter.ceval(code)
