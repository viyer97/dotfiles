set nocompatible
filetype off

set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

Plugin 'VundleVim/Vundle.vim'

Plugin 'scrooloose/nerdtree'
call vundle#end()
filetype plugin indent on

"automatically open tree window and sets to edit file window
autocmd vimenter * NERDTree
autocmd BufEnter * NERDTreeMirror
autocmd VimEnter * wincmd w
let NERDTreeMinimalUI = 1
let NERDTreeDirArrows = 1

"automatically closes NERDTree is only file left
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q | endif

"faster escaping
:imap wj <Esc>
:imap jw <Esc>

"faster screen switching
nnoremap <c-j> <c-w>j
nnoremap <c-k> <c-w>k
nnoremap <c-h> <c-w>h
nnoremap <c-l> <c-w>l

"real programmers use spaces
set tabstop=4
set shiftwidth=4
set expandtab

"ignore compiled files
set wildignore=*.o,*~,*.pyc

"set line numbers
set number
highlight LineNr term=bold cterm=NONE ctermfg=Grey ctermbg=NONE 

"no annoyting noises
set noerrorbells

"indentation and stuff
set smarttab
set si
