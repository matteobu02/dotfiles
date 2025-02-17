local actions = require('telescope.actions')

require('telescope').setup{
	defaults = {
		mappings = {
			i = {
				['<C-j>'] = actions.move_selection_next, -- move to next result
				['<C-k>'] = actions.move_selection_previous, -- move to prev result
				['<C-q>'] = actions.send_selected_to_qflist + actions.open_qflist, -- send selected to quickfixlist
				['<esc>'] = actions.close,
				['<CR>'] = actions.select_default + actions.center,
			},
			n = {
				['<C-j>'] = actions.move_selection_next, -- move to next result
				['<C-k>'] = actions.move_selection_previous, -- move to prev result
				['<C-q>'] = actions.send_selected_to_qflist + actions.open_qflist, -- send selected to quickfixlist
				['<esc>'] = actions.close,
				['<CR>'] = actions.select_default + actions.center,
			},
		}
	}
}


local builtin = require('telescope.builtin')

vim.keymap.set('n', '<leader>ff', builtin.find_files, {})
vim.keymap.set('n', '<leader>fr', builtin.lsp_references, {})
vim.keymap.set('n', '<leader>gf', builtin.live_grep, {})
vim.keymap.set('n', '<leader>gr', function()
	builtin.grep_string({ search = vim.fn.input('Grep > ') })
end)
