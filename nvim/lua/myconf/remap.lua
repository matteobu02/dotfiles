-- move selected lines up and down
vim.keymap.set('v', 'J', ":m '>+1<CR>gv=gv")
vim.keymap.set('v', 'K', ":m '>-2<CR>gv=gv")

-- keep cursor in place
vim.keymap.set('n', 'J', "mzJ`z")

-- keep cursor in the center of the screen when jumping
vim.keymap.set('n', '<C-d>', "<C-d>zz")
vim.keymap.set('n', '<C-u>', "<C-u>zz")
vim.keymap.set('n', '<C-o>', "<C-o>zz")
vim.keymap.set('n', '<C-f>', "<C-f>zz")
vim.keymap.set('n', '<C-b>', "<C-b>zz")
vim.keymap.set('n', 'n', "nzzzv")
vim.keymap.set('n', 'N', "Nzzzv")

-- always use system clipboard as yank register
vim.keymap.set('n', 'y', "\"+y")
vim.keymap.set('v', 'y', "\"+y")

-- raplace word beneath the crusor
vim.keymap.set('n', '<leader>s', ":%s/\\<<C-r><C-w>\\>/<C-r><C-w>/gI<Left><Left>")

-- disable search highlighting
vim.keymap.set('n', '<leader>n', vim.cmd.noh)
