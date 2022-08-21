set number
set mouse=a
set nowrap

"Allows vim to search for a file down
"to 2 sub-directories deep
set path+=**

function! CustomGeneralHighlight()
	hi Normal		ctermfg=252 ctermbg=234
	hi LineNr		ctermfg=243 ctermbg=235
	hi Comment		ctermfg=59
	hi StatusLine	ctermfg=235 ctermbg=243
	hi Statement	ctermfg=197
endfunction

function! CustomCppHighlight() abort
	let g:cpp_function_highlihgt = 0
	let g:cpp_attributes_highlight = 0
	let g:cpp_member_highlight = 0
	let g:cpp_simple_highlight = 0

	hi cComment				ctermfg=59
	hi cType				ctermfg=lightblue
	hi cStructure			ctermfg=lightblue
	hi cUserFunction		ctermfg=121
	hi cInclude				ctermfg=197
	hi cDefine				ctermfg=197
	hi cStatement			ctermfg=197
	hi cStorageClass		ctermfg=197
	hi cOperator			ctermfg=197
	hi cConditional			ctermfg=197
	hi cRepeat				ctermfg=197
	hi cFloat				ctermfg=141
	hi cConstant			ctermfg=141
	hi cNumber				ctermfg=141
	hi cSpecialCharacter	ctermfg=141
	hi cIncluded			ctermfg=186
	hi cString				ctermfg=186
	hi cCharacter			ctermfg=186
	hi cPreCondit			ctermfg=148

	hi cppSTLexception		ctermfg=lightblue
	hi cppSTLtype			ctermfg=lightblue
	hi cppSTLnamesapce		ctermfg=NONE
	hi cppSTLoperator		ctermfg=197
	hi cppStatement			ctermfg=197
	hi cppExceptions		ctermfg=197
	hi cppNumber			ctermfg=141

endfunction

function! CustomPythonHighlight() abort
	let g:python_highlight_all = 1
	hi pythonClass			ctermfg=lightblue
	hi pythonFString		ctermfg=lightblue
	hi pythonFunctionCall	ctermfg=lightblue
	hi pythonBuiltinFunc	ctermfg=lightblue
	hi pythonConditional	ctermfg=197
	hi pythonStatement		ctermfg=197
	hi pythonImport			ctermfg=197
	hi pythonOperator		ctermfg=197
	hi pythonRepeat			ctermfg=197
	hi pythonFunction		ctermfg=148
	hi pythonClassVar		ctermfg=215
	hi pythonNumber			ctermfg=141
	hi pythonFloat			ctermfg=141
	hi pythonNone			ctermfg=141
	hi pythonBoolean		ctermfg=141
	hi pythonStrFormat		ctermfg=141
	hi pythonString			ctermfg=186
	hi pythonBuiltinObj		ctermfg=7
endfunction

"Plugins
call plug#begin('~/.vim/plugged')

"Plug 'crusoexia/vim-monokai'
Plug 'pandark/42header.vim'
Plug 'vim-scripts/AutoComplPop'
Plug 'vim-python/python-syntax'
Plug 'bfrg/vim-cpp-modern'

call plug#end()

""colorscheme default
syntax on
call CustomGeneralHighlight()
call CustomPythonHighlight()
call CustomCppHighlight()

"colorscheme monokai
nmap <f1> :FortyTwoHeader<CR>

"Autocompletition
inoremap " ""<left>
inoremap ' ''<left>
inoremap ( ()<left>
inoremap [ []<left>
inoremap { {}<left>

set complete+=ksepll
set completeopt=menuone,longest
set shortmess+=c

"Activate indentation
filetype off
filetype plugin indent on
set smartindent

"Non-expanded, 4-wide tabulations
set tabstop=4
set shiftwidth=4
set noexpandtab

"Disable vi-compatibility
set nocompatible

"Real-world encoding
set encoding=utf-8

"Interpret modelines in files
set modelines=1

"Do not abandon buffers
set hidden

"Don't bother throttling tty
set ttyfast

"More useful backspace behavior
set backspace=indent,eol,start

"Use statusbar on all windows
set laststatus=2

"Better search
set ignorecase
set smartcase
set incsearch
set showmatch
set hlsearch

"Prevent backups when editing system files
au BufWrite /private/tmp/crontab.* set nowritebackup
au BufWrite /private/etc/pw.* set nowritebackup

"Returns the value of of a hughlight group
":echo synIDattr(synIDtrans(hlID('')), 'fg')
