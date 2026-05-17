public class ProductController {

    // Product object
    public Product__c pro {get; set;}

    // Product list
    public List<Product__c> productList {get; set;}

    // Constructor
    public ProductController() {

        pro = new Product__c();

        loadProducts();
    }

    // Load all products
    public void loadProducts() {

        productList = [

            SELECT Id,
                   Name,
                   Product_Name__c,
                   Serial_No__c,
                   Manufacture_Date__c,
                   Expiry_Date__c

            FROM Product__c

            ORDER BY CreatedDate DESC
        ];
    }

    // Save product
    public PageReference saveProduct() {

        insert pro;

        pro = new Product__c();

        loadProducts();

        return null;
    }

    // Delete product
    public PageReference deleteProduct() {

        String productId = ApexPages.currentPage()
                        .getParameters()
                        .get('delId');

        Product__c p = [

            SELECT Id
            FROM Product__c
            WHERE Id = :productId
        ];

        delete p;

        loadProducts();

        return null;
    }
}






<apex:page controller="ProductController">

    <apex:form >

        <!-- FORM -->

        <apex:pageBlock title="Product Inventory Management System">

            <apex:pageBlockSection columns="1">

                <!-- Product Name -->

                <apex:inputText value="{!pro.Product_Name__c}"
                    label="Product Name"/>

                <!-- Serial No -->

                <apex:inputText value="{!pro.Serial_No__c}"
                    label="Serial No"/>

                <!-- Manufacture Date -->

                <apex:inputField value="{!pro.Manufacture_Date__c}"/>

                <!-- Expiry Date -->

                <apex:inputField value="{!pro.Expiry_Date__c}"/>

                <!-- Save Button -->

                <apex:commandButton value="Save Product"
                    action="{!saveProduct}"
                    rerender="productTable"/>

            </apex:pageBlockSection>

        </apex:pageBlock>

        <br/>

        <!-- PRODUCT TABLE -->

        <apex:pageBlock title="Product Records"
            id="productTable">

            <apex:pageBlockTable value="{!productList}"
                var="p">

                <!-- Product Record -->

                <apex:column value="{!p.Name}"
                    headerValue="Record ID"/>

                <!-- Product Name -->

                <apex:column value="{!p.Product_Name__c}"
                    headerValue="Product Name"/>

                <!-- Serial No -->

                <apex:column value="{!p.Serial_No__c}"
                    headerValue="Serial No"/>

                <!-- Manufacture Date -->

                <apex:column value="{!p.Manufacture_Date__c}"
                    headerValue="Manufacture Date"/>

                <!-- Expiry Date -->

                <apex:column value="{!p.Expiry_Date__c}"
                    headerValue="Expiry Date"/>

                <!-- Delete -->

                <apex:column headerValue="Action">

                    <apex:commandLink value="Delete"
                        action="{!deleteProduct}">

                        <apex:param name="delId"
                            value="{!p.Id}"/>

                    </apex:commandLink>

                </apex:column>

            </apex:pageBlockTable>

        </apex:pageBlock>

    </apex:form>

</apex:page>


Do auto number here 