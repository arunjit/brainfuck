-- Tuprules.lua

function compile(source, output)
  tup.definerule{
    inputs = {source},
    command = 'clang ' .. source .. ' -o ' .. output,
    outputs = {output},
  }
end

-- Tupfile.lua

compile('brainfuck.c', 'brainfuck')
