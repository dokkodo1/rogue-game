{
  description = "C + Ncurses development environment";

  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

  outputs = { self, nixpkgs }:
    let
      system = "x86_64-linux";
      pkgs = nixpkgs.legacyPackages.${system};
    in
    {
      devShells.${system}.default = pkgs.mkShell {
        packages = with pkgs; [
          gcc
          gnumake
          pkg-config
          gdb
          ncurses
        ];
        PKG_CONFIG_PATH = "${pkgs.ncurses.dev}/lib/pkgconfig";
        shellHook = ''
          echo "C + Ncurses dev shell — ncurses $(pkg-config --modversion ncurses)"
        '';
      };
    };
}

