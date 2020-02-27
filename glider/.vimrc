execute pathogen#infect()
syntax on
filetype plugin indent on " highlight current line


" VIM KEY BEHAVIOUR
let mapleader=","  " <leader> is comma
"nnoremap \el <esc>
nnoremap <Space> <NOP>

" VIM AUTO FORMATING BEHAVIOR
au FileType * set fo-=c fo-=r fo-=o
	" Automatically disable auto formatting
inoremap <C-r> <C-o>:set formatoptions-=cro<CR>
inoremap <C-e> <C-o>:set formatoptions+=cro<CR>
inoremap <C-Space> <C-o>:set formatoptions-=cro<CR><CR><C-o>:set formatoptions+=cro<CR>



" FORMATING VISUALS

nmap <leader><space> :set list! <CR>
set listchars=tab:>-,space:•,extends:>,precedes:<



" EDITING TOOLS

nnoremap <leader>l :s/$/\=repeat(' ',64-virtcol('$'))


" truncate line 'line' to no more than 'limit' width
function! Truncate( line, limit )
  call cursor(a:line,a:limit)
  norm d$
endfunc

" Pad all lines with trailing blanks to 'limit' length.
function! AtOnce( limit )
  norm mm
  g/^/norm 100A
  g/^/call Truncate( getline('.'), a:limit )
  let @/=""
  norm 'm
endfunc






" WINDOW
nnoremap <A-Left> <C-w>h
nnoremap <A-up> <C-w>k
nnoremap <A-Down> <C-w>j
nnoremap <A-Right> <C-w>l
nnoremap ,v :vsplit
nnoremap ,h :split

" TABES
nnoremap <Tab> :tabp <CR>
nnoremap <S-Tab> :tabn <CR>
nnoremap q<Tab> :tabe 
set mouse=a

noremap <leader>1 1gt
noremap <leader>2 2gt
noremap <leader>3 3gt
noremap <leader>4 4gt
noremap <leader>5 5gt
noremap <leader>6 6gt
noremap <leader>7 7gt
noremap <leader>8 8gt
noremap <leader>9 9gt
noremap <leader>0 :tablast<cr>

nnoremap <C-S-Left> gt
nnoremap <C-S-Right> Gt

" BUFFERS
nnoremap <leader>b :buffer
nnoremap <S-A-Left> :bprevious<CR>
nnoremap <S-A-Right> :bnext<CR>
nnoremap <leader>q :bdelete

" TABS_KEY
set tabstop=2 " number of visual spacesper TAB
set softtabstop=1 "number of spaces in tab when editing
set expandtab

" POSITION GUIDES & VISUAL AIDS
set number
set cursorline
set showmatch
set ruler
nnoremap <leader>r :set invrelativenumber<CR>
nnoremap gV `[v`]

" COMMAND ASSIST
set showcmd " show command in bottom bar
set wildmenu " visual autocomplete for command menu

" DRAW SETTINGS
set lazyredraw " redraw only when we need to

" COPY PASTE (DIFFERENT VIM SESSIONS) - requires xsel (there is optionally xclip -i/o -sel c/-c)
vnoremap <leader>y :w !xsel -i -b <CR>
vnoremap <leader>p :r !xsel -o -b <CR>

" SEARCH SETTINGS
set incsearch " search as characters are entered
set hlsearch " highlight matches
nnoremap <leader>/ :nohlsearch<CR>
    " space will clear highlighting from search




" FOLD SETTINGS
set foldenable " Enable folds
set foldmethod=indent " manual indent syntax expr marker diff - https://vim.fandom.com/wiki/Folding
set shiftwidth=2 " indent = indent of line / shiftwidth (rounded down)
set foldcolumn=3 " Width of column side bar
set foldlevelstart=1 " Open foldlevel when file is opened
nnoremap <silent><space> @=(foldlevel('.')?'za':"\<space>")<CR>
    " if on fold space willopen/close folding, else move left 1 character
nnoremap z<Up> zk
nnoremap z<Down> zj
vnoremap <space> xf
    " in visual mode, selected rows will become a fold (normal and marker mode only)

" TIMEOUT
set timeoutlen=1000 " Time Vim will wait for the different parts of a terminal
set ttimeoutlen=10 " Time Vim will wait for the successive Vim keycodes, entered by the user

" JUMP
set viminfo='100,f1 " Save jumps for 100 files -> save global marks

" EXECUTION
nnoremap <F1> <ESC>:w<CR>:!clear;gcc % -c <CR>
nnoremap <F1> <ESC>:w<CR>:!clear;make<CR>
nnoremap <F1> <ESC>:w<CR>:!clear;make clobber<CR>
nnoremap <F1> <ESC>:w<CR>:!clear;python %<CR>


"
" VIM PLUGINS
"

" gundo - Install with git clone http://github.com/sjl/gundo.vim.git ~/.vim/bundle/gundo
map <leader>u :GundoToggle<CR>
if has('python3')
    let g:gundo_prefer_python3 = 1
endif
let g:gundo_right = 0
let g:gundo_width = 60
let g_gundo_preview_height = 40
let g:gundo_preview_bottom = 1
let g:gundo_right = 1

" vim-airline - update w/ $ cd ~/.vim/bundle/vim-airline && git pull origin master
set laststatus=2 " Display the status line always
let g:airline#extensions#tabline#enabled = 1
let g:airline#extensions#tabline#formatter = 'unique_tail_improved'
    " 'default' 'jsformatter' 'unique_tail' 'unique_tail_improved'
let g:airline#extensions#whitespace#enabled = 1


" nerdtree - git clone https://github.com/preservim/nerdtree.git ~/.vim/bundle/nerdtree
map <Leader>n :NERDTreeToggle<CR>
    " opens nerd tree
let g:NERDTreeNodeDelimiter = "\u00a0" " magic fix for '^G' glitch
autocmd StdinReadPre * let s:std_in=1
autocmd VimEnter * if argc() == 0 && !exists("s:std_in") | NERDTree | endif
    " start automatically if no file was specified
autocmd StdinReadPre * let s:std_in=1
autocmd VimEnter * if argc() == 1 && isdirectory(argv()[0]) && !exists("s:std_in") | exe 'NERDTree'argv()[0] | wincmd p | ene | exe 'cd '.argv()[0] | endif
    " start automatically if opening a file directory
    " exe 'cd '.argv()[0] sets the pwd of the new edit window to ~/some-directory
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q | endif
    " close window if only nerd tree is left
let g:NERDTreeDirArrowExpandable = '▸'
let g:NERDTreeDirArrowCollapsible = '▾'

" Open newtab on mouseclick
autocmd VimEnter * call NERDTreeAddKeyMap({ 'key': '<2-LeftMouse>', 'scope': "FileNode", 'callback': "OpenInTab", 'override':1 })
function! OpenInTab(node)
	call a:node.activate({'reuse': 'all', 'where': 't'})
endfunction

"let NERDTreeMapOpenInTab='<ENTER>'
	" Open nerd tree in new tab


" vim-bbye - git clone https://github.com/moll/vim-bbye.git ~/.vim/bundle/bbye
"		-- For better management of buffers
nnoremap <Leader>q :Bdelete<CR>
	" Delete current buffer
