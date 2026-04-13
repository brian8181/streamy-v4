-- Simple plugin declaration
vim.pack.add({
  'https://github.com/nvim-treesitter/nvim-treesitter',
  'https://github.com/neovim/nvim-lspconfig',
  
  -- Specifying a version or custom name
  { 
    src = 'https://github.com/sainnhe/gruvbox-material', 
    version = 'v2.0.0' 
  },
})

-- Load a theme after it's been added
vim.cmd('colorscheme gruvbox-material')
