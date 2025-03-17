#include "tabela_hash.h"
#include "priority_queue.h"
#include "arvore.h"
#include "bit_map.h"
int main(){
    
    
    FILE* arq = fopen("./arq.bin","wb");

    BIT_MAP* bm = create_bit_map(1);

    char num[9] = {1,1,1,1,1,1,0,0,1};

    for(int i=0; i<9; i++){
        write_bitmap(bm, num[i]);
    }

    fwrite(get_vet_bitmap,1,1,arq);

    fclose(arq);

    FILE* fp = fopen("./arq.bin", "wr");
    fread(get_vet_bitmap(bm),1,1,fp);
    update_curr_idx_bitmap(bm, 0);
    print_bitmap(bm);
    

    return 0;
}