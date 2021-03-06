# 입/출력 포트 정보 입력

등록하는 사이언스 앱의 입출력 파일에 대한 정보를 입력하는 부분이다.  

![](image/image11.png)

(1) 입력 포트 값에 따른 간략한 Command Line을 조회 할 수 있습니다.

 - 입력한 입력 포트 정보와 앞에서 입력한 파일 명 정보를 토대로 커멘드 라인을 생성합니다. 실제 앱이 실행되는 경우 해당 커멘드 라인으로 생성되니, 실행 파일이 해당 커멘드 라인으로 실행되는지 확인해야 합니다.

(2) 생성된 입력 포트 정보 리스트를 확인 할 수 있습니다.

 - 순번 : 생성한 입력 포트의 순번을 표시한다.
 - 포트명 : 설정된 포트명을 표시한다. 포트명은 실행 파일의 커멘드 옵션과 동일한 의미이다.
 - 포트 타입명 : 생성된 입력 포트의 포트 타입명을 나타낸다. 입력 파일의 타입을 나타내며, 입력 포트 추가 시 새롭게 생성하거나 기존에 생성된 포트 타입을 선택할 수 있다. 
 - InputDeck Port : 해당 포트가 인풋덱 에디터를 사용하는지 여부를 표시해준다.
 - 필수 : 앱을 실행하는 사용자가 해당 포트에 입력 파일 생성을 반드시 해야하는지에 대한 여부를 결정할 수 있다. Y인 경우 해당 포트의 입력 파일을 생성해야 하며, N인 경우 입력 파일을 만들지 않아도 앱을 실행할 수 있다. 옵션 입력 파일 등을 생성할 때 필수 값을 "N"로 설정해주면 된다.
 - 삭제 : 해당 포트를 삭제하고자 하는 경우 삭제 버튼을 클릭하여 삭제 할 수 있다.

(3) 입력 포트를 선택하는 팝업 창을 실행 할 수 있습니다.

- 입력 포트를 생성하고자 하는 경우 해당 메뉴를 클릭하면 된다. 이후 포트 명을 입력하고, 등록된 포트 타입을 검색하거나 새롭게 포트 타입을 생성 할 수 있다. 

(4) 출력 포트의 기본정보 및 상태를 확인 할 수 있습니다.

 - 순번 : 생성한 출력 포트의 순번을 표시한다.
 - 포트명 : 설정된 포트명을 표시한다. 
 - 포트 타입명 : 생성된 출력 포트의 포트 타입명을 나타낸다. 출력 파일의 타입을 나타내며, 출력포트 추가시 새롭게 생성하거나 기존에 생성된 포트 타입명을 선택할 수 있다. 
 - Data Type : 출력 포트의 데이터 형태를 설정할 수 있다. File, Extention, Folder 등으로 선택 할 수 있다.
 - File name : 데이터 타입이 file인 경우 파일명을, Extention인 경우 확장자 이름을, Folder인 경우 생성된 폴더 명을 입력해 준다.
 - 삭제 : 해당 포트를 삭제하고자 하는 경우 삭제 버튼을 클릭하여 삭제 할 수 있다.

(5) 출력 포트를 선택하는 팝업 창을 실행 할 수 있습니다.

- 출력 포트를 생성하고자 하는 경우 해당 메뉴를 클릭하면 된다. 이후 포트 명을 입력하고, 등록된 포트 타입을 검색하거나 새롭게 포트 타입을 생성 할 수 있다. 

(6) 개발한 앱의 모든 입출력 포트 정보를 작성하였으면, 저장 버튼을 선택하여 현재 상태를 저장 한 후 다음 단계인 ‘앱 테스트’ (탭 메뉴 앱 테스트)로 이동한다.

 - 출력 포트 이름이 temp 이면 모니터링에서 중간 확인을 할 수 있습니다.
 - 입/출력 포트 정보를 저장한 후 다음 단계로 이동 할 수 있습니다.