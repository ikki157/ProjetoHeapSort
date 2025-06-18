 const generateBtn = document.getElementById('generateInputsBtn');
        const sizeInput = document.getElementById('arraySize');
        const inputsContainer = document.getElementById('arrayInputsContainer');
        const sortForm = document.getElementById('heapSortForm');
        const sortButton = document.getElementById('sortButton');
        const outputContainer = document.getElementById('outputContainer');
        const outputEl = document.getElementById('output');

        generateBtn.addEventListener('click', () => {
            const size = parseInt(sizeInput.value);
            if (isNaN(size) || size < 1) {
                alert('Por favor, insira um tamanho de array válido.');
                return;
            }

            inputsContainer.innerHTML = `<label>2. Insira os ${size} números do array:</label>`;
            const inputsWrapper = document.createElement('section');
            inputsWrapper.className = 'array-inputs';

            for (let i = 0; i < size; i++) {
                const input = document.createElement('input');
                input.type = 'number';
                input.name = `val${i}`;
                input.placeholder = `${i+1}° número`;
                input.required = true;
                inputsWrapper.appendChild(input);
            }
            inputsContainer.appendChild(inputsWrapper);
            sortButton.style.display = 'block';
        });

        sortForm.addEventListener('submit', async (event) => {
            event.preventDefault(); // Impede o envio tradicional do formulário
            
            outputContainer.style.display = 'block';
            outputEl.textContent = 'Processando...';

            const formData = new FormData(sortForm);
            const cgiUrl = '/cgi-bin/heap_sort.cgi'; 

            const params = new URLSearchParams(formData);

            try {
                const response = await fetch(`${cgiUrl}?${params.toString()}`);
                if (!response.ok) {
                    throw new Error(`Erro do servidor: ${response.status} ${response.statusText}`);
                }
                const resultText = await response.text();
                outputEl.textContent = resultText;
            } catch (error) {
                outputEl.textContent = `Ocorreu um erro ao conectar com o script C:\n\n${error}\n\nVerifique se o servidor web está rodando e o caminho para o script CGI está correto.`;
            }
        });